// Matching warm rear light (brake / reverse) – optional but recommended
class vg7ScorpionRearLight extends CarRearLightBase
{
	void vg7ScorpionRearLight()
	{
		// Brake light – classic red
		m_SegregatedBrakeBrightness = 1.0;
		m_SegregatedBrakeRadius = 8;
		m_SegregatedBrakeAngle = 160;
		m_SegregatedBrakeColorRGB = Vector(1.0, 0.05, 0.05);

		// Reverse light – warm white / slight yellow
		m_SegregatedBrightness = 1.2;
		m_SegregatedRadius = 12;
		m_SegregatedAngle = 140;
		m_SegregatedColorRGB = Vector(1.0, 0.9, 0.7);

		// Aggregated values
		m_AggregatedBrakeBrightness = 1.2;
		m_AggregatedBrakeRadius = 10;
		m_AggregatedBrakeAngle = 170;
		m_AggregatedBrakeColorRGB = Vector(1.0, 0.05, 0.05);

		m_AggregatedBrightness = 1.5;
		m_AggregatedRadius = 15;
		m_AggregatedAngle = 150;
		m_AggregatedColorRGB = Vector(1.0, 0.92, 0.75);

		FadeIn(0.1);
		SetFadeOutTime(0.1);
		SegregateLight();
	}
};
