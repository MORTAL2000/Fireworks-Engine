#include "audioclip.h"

namespace fireworks { namespace audio {

	ALboolean AudioClip::s_g_bEAX = alIsExtensionPresent("EAX2.0");
	ALCdevice* AudioClip::s_Device = alcOpenDevice(NULL);
	ALCcontext* AudioClip::s_Context = alcCreateContext(s_Device, NULL);

	AudioClip::AudioClip(const std::string& filePath)
		: gain(0), pitch(0), m_FilePath(filePath), m_DidPlayOnce(false)
	{
		init();
		load();
	}

	AudioClip::~AudioClip()
	{
		alDeleteSources(1, &m_Source);
		alDeleteBuffers(1, &m_BufferID);

		alcDestroyContext(s_Context);
		alcCloseDevice(s_Device);
		delete[] m_Data;
	}

	void AudioClip::Play()
	{
		if (m_EnableLooping)
			alSourcei(m_Source, AL_LOOPING, AL_TRUE);
		else
			alSourcei(m_Source, AL_LOOPING, AL_FALSE);

		ALenum error = alGetError();
		if (error != AL_NO_ERROR)
			std::cerr << "ERROR::OPEANAL:: " << error << std::endl;

		alSourcePlay(m_Source);
		m_DidPlayOnce = true;
	}

	void AudioClip::Stop()
	{
		alSourceStop(m_Source);
	}

	void AudioClip::Replay()
	{
		alSourceRewind(m_Source);
	}

	void AudioClip::PlayOnce()
	{
		if (!this->isPlaying())
			this->Play();
	}

	void AudioClip::PlayOnceOnly()
	{
		if (!this->isPlaying() && !this->didPlayonce())
			this->Play();
	}

	void AudioClip::Loop()
	{
		this->m_EnableLooping = true;
		if (!this->isPlaying())
			this->Play();
	}

	void AudioClip::Pause()
	{
		alSourcePause(m_Source);
	}

	void AudioClip::init()
	{
		if (s_Device)
		{
			alcMakeContextCurrent(s_Context);
		}
		else
		{
			std::cerr << "ERROR::OPEANAL:: Cannot create device and context" << std::endl;
			return;
		}

		alGenBuffers(1, &m_BufferID);
		alGenSources(1, &m_Source);
	}

	void AudioClip::load()
	{
		m_Data = m_WavLoader.loadWAV(m_FilePath.c_str(), m_AudioFormat, m_SampleRate, m_BitsPerSecond, m_Size);

		alBufferData(m_BufferID, m_AudioFormat, m_Data, m_Size, m_SampleRate);
		alSourcei(m_Source, AL_BUFFER, m_BufferID);
	}

	void AudioClip::enableStreamingMode()
	{
		std::clog << "ERROR::OPENAL:: Doesn't support strteaming yet!" << std::endl;
	}
} }
